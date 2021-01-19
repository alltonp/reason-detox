//NOTE: missing a trick here, we should be actioning/expecting on elements not Matchers?
//hence... await expect(element(by.id('UniqueId204'))).toHaveText('I contain some text');

//matchers
[@bs.module "./ReasonDetox.js"]
external byId: (~id: string) => string = "by_id";

[@bs.module "./ReasonDetox.js"]
external byText: (~text: string) => string = "by_text";

//actions
[@bs.module "./ReasonDetox.js"]
external doTap: (~by: string) => Js.Promise.t(unit) = "element_tap";

[@bs.module "./ReasonDetox.js"]
external doTypeTextId: (~id: string, ~value: string) => Js.Promise.t(unit) =
  "detox_element_id_typeText";

[@bs.module "./ReasonDetox.js"]
external doExpectToBeVisible: (~text: string) => Js.Promise.t(unit) =
  "detox_expect_text_toBeVisible";

[@bs.module "./ReasonDetox.js"]
external doExpectToHaveText:
  (~id: string, ~expected: string) => Js.Promise.t(unit) =
  "detox_expect_id_toHaveText";

exception Failure({reason: string});

let errorMessage = x => Obj.magic(x);

let raiseError = err => {
  err->Js.Console.error;
  raise(Failure({reason: err->errorMessage}));
};
