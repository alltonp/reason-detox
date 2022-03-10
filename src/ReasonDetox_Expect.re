//TIP: see https://github.com/wix/Detox/blob/master/docs/APIRef.Expect.md
//TOOD: think about pipe-first vs last etc
module Expect = {
  open ReasonDetox_Matchers;
  open Matchers;
  open ReasonDetox_Bindings;

  let expectToBeVisible = by =>
    Js.Promise.(
      (
        switch (by) {
        | Text(v) => doExpectToBeVisibleText(~text=v)
        | Id(v) => doExpectToBeVisibleId(~id=v)
        }
      )
      |> catch(err => {err->raiseError})
      |> then_(_ => {resolve()})
    );

  let expectToExist = by =>
    Js.Promise.(
      (
        switch (by) {
        | Text(_v) => raise(Failure({reason: "Unsupported"}))
        | Id(v) => doExpectToExistId(~id=v)
        }
      )
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