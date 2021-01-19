//TIP: see https://github.com/wix/Detox/blob/master/docs/APIRef.Expect.md
//TOOD: think about pipe-first vs last etc
module Expect = {
  open ReasonDetox_Matchers;
  open Matchers;
  open ReasonDetox_Bindings;

  //TODO: should take a by
  let expectToBeVisible = text =>
    Js.Promise.(
      doExpectToBeVisible(~text)
      |> catch(err => {err->raiseError})
      |> then_(_ => {resolve()})
    );

  let toHaveText = (expected, by) =>
    Js.Promise.(
      (
        switch (by) {
        | Text(_v) => raise(Failure({reason: "Unsupported"}))
        | Id(v) => doExpectToHaveText(~id=v, ~expected)
        }
      )
      |> catch(err => {err->raiseError})
      |> then_(_ => {resolve()})
    );
};
