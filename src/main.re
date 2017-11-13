[%bs.raw {| Github$1.Api = Github$1 |}];

Js.log("--- Start app ---");

let api = Github.Api.make({"version": "3.0.0"});

Js.log(api);

let service = Github.Service.make("1111");

Js.log(service);

Js.log(service#getUsers());

open Vscode;

Vscode.Window.showInformationMessage("aaa");
