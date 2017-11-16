[%bs.raw {| Github$1.Api = Github$1 |}];

Js.log("--- Start app ---");

let service = Github.Service.make("1111");

Js.Promise.(
    service#getUsers()
    |> then_((i) => resolve(i))
);

open Vscode;

Vscode.Window.showInformationMessage("aaa");
