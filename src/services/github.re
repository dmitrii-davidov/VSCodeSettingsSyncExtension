module Api = {
  type api = {
    .
    "users": {. "get": unit => Js.Promise.t(int)}, "authenticate": (~token: string) => unit
  };
  type config = {. "version": string};
  [@bs.module "github"] [@bs.new] external make : config => api = "Api";
};

module Service = {
  type service = {. getUsers: unit => Js.Promise.t(int)};
  let make: string => service =
    (token) => {
      let api = Api.make({"version": "3.0.0"});
      let apiGetUsers = api##users##get;
      let apiAuthenticate = api##authenticate;
      apiAuthenticate(~token);
      {pub getUsers = apiGetUsers}
    };
};
