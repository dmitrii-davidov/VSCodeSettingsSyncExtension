[%bs.raw {| Github.Api = Github |}];

type api;

module Api = {
  type t = api;
  type users;

  type config = {. "version": string};
  [@bs.module "github"] [@bs.new] external make : config => t = "Api";

  [@bs.send.pipe: t] external authenticate : {. "type": string, "token": string} => unit = "";
  [@bs.get] external users : t => users = "";

  module Users = {
    type t = users;

    [@bs.send.pipe: t] external _get :{.} => Js.Promise.t(string) = "get";
    let get = (api) => api |> users |> _get({});
  };
};

module Service = {
  type service = {. getUsers: unit => Js.Promise.t(string)};
  let make: string => service =
    (token) => {
      let api =  Api.make({"version": "3.0.0"});
      api |> Api.authenticate({"type": "oauth", "token": token});
      {pub getUsers = () => api |> Api.Users.get }
    };
};
