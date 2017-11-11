[%bs.raw {| Github$1.Api = Github$1 |}];

Js.log("--- Start app ---");

let api = Github.Api.init({"version": "3.0.0"});
Js.log(api);

let service = Github.Service.init("1111");
Js.log(service);
Js.log(service#authenticate());

open Vscode;

Vscode.Window.showInformationMessage("aaa");
