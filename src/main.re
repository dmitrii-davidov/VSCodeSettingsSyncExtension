Js.log("--- Start app ---");

let service = Github.Service.make("1111");



Js.Promise.(
    service#getUsers()
    |> then_(s => resolve(Js.log(s)))
    |> catch(e => {
        Js.log(e);
        resolve()
    })
);

/* open Vscode;

Vscode.Window.showInformationMessage("aaa"); */
