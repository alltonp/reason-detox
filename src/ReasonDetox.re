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
