# reason-detox

### installation
1. install detox for jest as per standard instructions
1. update `e2e/config.json` with:
    ```
    "testRegex": "\\Test\\.js$|\\Test\\.bs.js$",
    "transformIgnorePatterns": [
      "node_modules/(?!(jest-)?react-native|react-(native|universal|navigation)-(.*)|@react-native-community/(.*)|@react-navigation/(.*)|bs-platform|(@[a-zA-Z]+/)?(bs|reason|rescript)-(.*)+)"
    ]
    ```
1. in `bsconfig.json` add new source: 
    ```
    {
       "dir": "e2e",
       "type": "dev"
    }
    ```
   
1. run `npm install --save-dev bs-let` and add `"ppx-flags": ["bs-let/ppx"]` to `bsconfig.json`
1. that's it!

### creating a test
- save the following `e2e/TheTest.re` in 
```
open ReasonDetox;
open ReasonDetox.Actions;

describe("suite name", () => {
  it("example name", done_ =>
    {
      //TIP: everything that returns a Promise must use let%Await 
      let%Await _ = tap(Text("blah"));
      let%Await _ = assertText("title", "something");

      //TIP: must call this at the end to tell jest we are done, otherwise the test will run until timeout and then fail
      Js.Promise.resolve(done_());
    }
    ->ignore
  );
});
```

### running a test
- `detox test -f e2e/TheTest.bs.js` 

## troubleshooting
- when running jest complains about being unable to parse Block, Curry etc... make sure you have the transformIgnorePatterns set in `e2e/config.json`


### known issues
- (not sure about this anymore, now that transform is fixed) have to use e.g. Js.List.x instead of Belt.List.x or List.x... need to find a workaround for that.

### notes
API: kind of want...
- await do athing |> await do another thing |> await do another thing
- or await do athing |> do another thing |> do another thing


TODO:
- tidy up api
- end test properly on fail (aka: call done on catch, maybe - yes otherwise test continues after first failure)
- find a way to kill the '->ignore' on it
- make before and after available... in jest bit
- think about Promise.all, if ordered then it could just work... - can we just have one let%Await _ = on a list and do Promise.all?
