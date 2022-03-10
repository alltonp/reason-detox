include ReasonDetox_Matchers;
include Matchers;
include ReasonDetox_Actions;
include Actions;
include ReasonDetox_Expect;
include Expect;

module Await = {
  let let_ = (prop, cb) => Js.Promise.then_(cb, prop);
};

let expect = by => by;

/*
 let awaitAll = ps => {
   ps->Belt.List.reduce(Js.Promise.resolve(), (p, v) => {
     p
     |> Js.Promise.then_(_ => {
          let%Await _ = v();
          //           Js.Console.log(v);
          Js.Promise.resolve();
        })
   });
 };
 */