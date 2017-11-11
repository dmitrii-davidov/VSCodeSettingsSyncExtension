/* type api = {
    .
    "authenticate": unit => unit,
}; */

[@bs] class type _api = {
    pub authenticate: unit => unit;
};
type api = Js.t(_api);

type config = {.
    "version" : string,
};

module Api = {
    type t = api;

    [@bs.module "github"] [@bs.new] external init : config  => t = "Api";
};

module Service = {
    type service = {.
        authenticate: unit => unit,
    };

    let init: string => service = (token) => {
        /* pri token = token; */
        let api = Api.init({"version": "3.0.0"});
        let api_authenticate = api##authenticate;

        {
            pub authenticate = () => api_authenticate();
        }
    };
}