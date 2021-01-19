////TIP: all very very experimental
//module Fluent = {
//  let andThen = (ps, p) => List.append(ps, [() => p]);
//
//  let run = ps => {
//    let all =
//      ps
//      ->Belt.List.map(p => {
//          let%Await _ = p();
//          Js.Promise.resolve();
//        })
//      ->Belt.List.toArray
//      ->Js.Promise.all;
//
//    let%Await _ = Js.Promise.resolve(all);
//    Js.Promise.resolve();
//  };
//};
//
////TIP: this is mega useful for clicking through to what you actually have...
//let byId3 = [%raw
//  {|
//  function(a) {
//    console.log("hello from raw JavaScript!");
//    return by.id(a)
//  }
//|}
//];
