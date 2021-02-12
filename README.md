# reason-detox

## what

[Reasonml/Rescript](https://rescript-lang.org) bindings for the [Detox](https://github.com/wix/Detox) end-to-end testing framework.

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
- install reason-detox
```bash
yarn add https://github.com/alltonp/reason-detox
```
- add `reason-detox` to `bsconfig.json`
```json
"bs-dependencies": ["reason-detox"]
```

- in `bsconfig.json` add new source:
    ```json
    {
       "dir": "e2e",
       "type": "dev"
    }
    ```
   
- update `e2e/config.json` with:
```json
"testRegex": "\\Test\\.js$|\\Test\\.bs.js$",
"transformIgnorePatterns": [
  "node_modules/(?!(jest-)?react-native|react-(native|universal|navigation)-(.*)|@react-native-community/(.*)|@react-navigation/(.*)|bs-platform|(@[a-zA-Z]+/)?(bs|reason|rescript)-(.*)+)"
]
```
- run `npm install --save-dev bs-let` and add `"ppx-flags": ["bs-let/ppx"]` to `bsconfig.json`
- that's it!

### creating a test
- save the following in `e2e/TheTest.re` 
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
- `detox test -f e2e/TheTest.bs.js` 

### running all tests
- `detox test`
