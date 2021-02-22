# reason-detox

## what

[Reasonml/Rescript](https://rescript-lang.org) bindings for the [Detox](https://github.com/wix/Detox) end-to-end testing framework. See [here](https://github.com/alltonp/reason-react-native-detox-tea) for a complete example project using this library.

## why
- you are using [reason-react-native](https://reason-react-native.github.io) and want to write end-to-end test's without introducing js 
- you are using plain old React Native and want to try introducing Reasonml in a lightweight way 

## status
- experimental but definitely usable, building blocks are there just needs a few more primitives adding

## how

### pre-installation
- install detox for jest as per the [standard instructions](https://github.com/wix/Detox/blob/master/docs/Introduction.GettingStarted.md)
- *ensure you can successfully run a standard detox test before continuing*   

### installation
1. install reason-detox
    ```bash
    yarn add --dev jest @glennsl/bs-jest bs-let https://github.com/alltonp/reason-detox
    ```
1. in `bsconfig.json`
    1. add `"@glennsl/bs-jest", "reason-detox"` to `"bs-dependencies"`
    1. add `"ppx-flags": ["bs-let/ppx"]`
    1. add to `"sources"`:
      ```json
      {
        "dir": "e2e",
        "type": "dev"
      }
      ```
1. update `e2e/config.json` with:
    ```json
      "testRegex": "\\Test\\.bs.js$",
      "transformIgnorePatterns": [
        "node_modules/(?!(jest-)?react-native|react-(native|universal|navigation)-(.*)|@react-native-community/(.*)|@react-navigation/(.*)|bs-platform|(@[a-zA-Z]+/)?(bs|reason|rescript)-(.*)+)"
      ]
    ```
1. that's it!

### creating a test
- save the following in `e2e/firstTest.re` 
```Reason
open Jest;
open ReasonDetox;

describe("The Test", () => {
  testPromise("example", _ => {
  
    //TIP: everything that returns a Promise must use let%Await 
    let%Await _ = expect(Id("count")) |> toHaveText("0");
    let%Await _ = tap(Text("+"));
    let%Await _ = expect(Id("count")) |> toHaveText("1");
    let%Await _ = tap(Text("-"));
    let%Await _ = expect(Id("count")) |> toHaveText("0");

    //TIP: must call this at the end to tell jest we are done, otherwise the test will run until timeout and then fail 
    Js.Promise.resolve(pass);
  })
});
```

### run the test
- `detox test -f e2e/firstTest.bs.js` 

### running all tests
- `detox test`
