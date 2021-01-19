//TIP: see https://github.com/wix/Detox/blob/master/docs/APIRef.ActionsOnElement.md
module Actions = {
  open ReasonDetox_Matchers;
  open Matchers;
  open ReasonDetox_Bindings;

  let tap = by =>
    Js.Promise.(
      {
        let matcher =
          switch (by) {
          | Text(v) => byText(~text=v)
          | Id(v) => byId(~id=v)
          };
        doTap(~by=matcher);
      }
      |> catch(err => {err->raiseError})
      |> then_(_ => {resolve()})
    );
  //        | Text(v) => doTapText(~text=v)

  let typeText = (by, value) =>
    Js.Promise.(
      {
        switch (by) {
        | Text(_v) => raise(Failure({reason: "Unsupported"}))
        | Id(v) => doTypeTextId(~id=v, ~value)
        //        doTap(
        //          ~by,
        //        );
        };
      }
      |> catch(err => {err->raiseError})
      |> then_(_ => {resolve()})
    );
};
