include ReasonDetox_Matchers;
include Matchers;
include ReasonDetox_Actions;
include Actions;
include ReasonDetox_Expect;
include Expect;

//not sure we need this now....
module Await = {
  let let_ = (prop, cb) => Js.Promise.then_(cb, prop);
};

let expect = by => by /*}*/ /*         //           Js.Console.log(v)*/ /*       }*/ /*  })*/ /*         Js.Promise.resolve()*/;

//would like this but, might need bs-let/ppx for it...
//let awaitAll = ps => {
//  ps->Belt.List.reduce(Js.Promise.resolve(), (p, v) => {
//    p
//    |> Js.Promise.then_(_ => {
//         let%Await _ = v();