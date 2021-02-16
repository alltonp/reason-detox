- make bs-jest a dep? (or peerDep?)
- make detox a dep? dont think we can
- support rescript?
- rename to rescript-detox?
- does bs-let need to me a dep? (or peerDep?)
- resolve production vs dev deps
- push to npm

------------------------

old, tidy or kill

### troubleshooting
- when running jest complains about being unable to parse Block, Curry etc... make sure you have the transformIgnorePatterns set in `e2e/config.json`

### notes

API: kind of want...
- await do athing |> await do another thing |> await do another thing
- or await do athing |> do another thing |> do another thing

TODO:
- tidy up api
- end test properly on fail (aka: call done on catch, maybe - yes otherwise test continues after first failure)
- make before and after available... in reason jest bit
- think about Promise.all, if ordered then it could just work... - can we just have one let%Await _ = on a list and do Promise.all?
