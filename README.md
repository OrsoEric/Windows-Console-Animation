# Windows-Console-Animation
Animate the windows console without taking in lots of dependencies\
**    Problem:\
**    I was searching for an easy way to animate the output console\
**    I wanted to display numbers changing in real time (weights of\
**    a neural network) without writing tons of lines or jumping to\
**    a big framework with tons of dependencies to handle\
**\
**        Process:\
**    The task that proved much trickier than expected and required lots of research\
**    Can I do it with C++ standard library alone? NO.\
**    Search for libraries and dependencies that achieve the objective.\
**    Are there libraries out there that do it? YES. Tons of them!\
**    Problem:\
**        Libraries I found are either full blown frameworks (QT, etc...) or\
**        non standard/unstable/compiler dependent mess (conio, etc...)\
**\
**        Solution:\
**    The reason small libraries are a mess IMHO is because they try to be more than what they are\
**    The simplest way with the least dependencies to do it is to make use of the OS APIs\
**    You lose some portability, but save time in solving dependencies\
**    Anima is a fairly thin wrapper that provides the minimum possible features\
**    to achieve the desired result.\
**    It's imperative that the library is consistent in what it does\
**\
**        Scope:\
**    Anima is meant to be quick, easy to use and require little to no messing with the compiler\
**    Anima is a basic library meant to do basic stuffs quickly\
**    Display numbers that change in real time? OK\
**    Press a key to tune a parameter? OK\
**    Little ascii game for fun and profit? OK\
**    Jpeg loader with ascii art converter? NO!\
**    ascii GUI drawing primitives? NO!!!\
**    Fractal ascii art drawing primitives? HELL NO!!!\
**\
**        Limitations:\
**    Anima works only on windows 2000 and above\
**    Anima provides only a virtual key buffer and an output buffer it's up to the user to do everything else\
**    If fancy things are required, than Anima is NOT the answer you are looking for
