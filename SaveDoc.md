To change the name of the output file, simpy change it in the ```Settings``` window.<br />
<br />
The file doesn't allow Windows ```CL LF``` endings and is structured as followed:<br />
<br />
The first line is a simple warning to be careful with this file.<br />
<br />
The following line includes important argument, as they were in the saved run.<br />
```{<int>,<int>,<int>,<int>,<int>,};``` is filled with ```{gridX,gridY,BunnyCount,foodCount,max_hunger};```, terminated with ```;``` and a simple new line. The last ```,``` is mandatory.<br />
```max_hunger``` is not available via the arguments, the value will be assumed if the correlating values are feeded. It is anyway only interesting, if you want to disable the feeding system.<br />
<br />
The next piece of information represents the food sources. There must be exactly the same amount of sources/lines as defined with ```foodCount```above.<br />
```{<int>,<int>,<int>}```simply represents the coordinates ```{x,y}``` and the amount of food left ```{food_duration}``` of one food source. At the end, there is again one simple newLine and the last food source is followed by one additional ```LF```newLine.<br />
<br />
The last and usually biggest part represents every single bunny, which was alive when the game was saved.
The number of Bunnies/lines must be the same as defined with ```BunnyCount``` above.<br />

```{<int> <int> <int> <string> <int> <int> <int> <int>}``` shows one Bunny with the values ```{sex color age Name isMutant daySinceLastEaten coordinate.x coordinate.y }```, this time separated with blancs.<br />
The bunnies to each other are again seperated with one simple newLine ```LF```.<br />

The ```Name```string cannot exceed the limit set with ```NAME_LEN``` chars, including one terminating ```'\0'```. It is defined in [functions.h](Bunnys/functions.h) and [bunny.h](Bunnys/bunny.h).<br />
<br />
At the end of the file is no additional newLine.
Common comments markups like ```//``` or ```--``` are NOT supported.
<br /><br />
This is like a working saved game could look:<br/>
```
!!The first line will be ignored, do whatever you want, just no newLines!!
{100,60,5,4,3,};
{63,4,3514,}
{86,45,1567,}
{84,1,57,}
{1,22,4717,}

{0 2 10 Werner_von_Braun 0 1 68 4 }
{1 2 7 Kimberly 0 1 63 3 }
{0 2 3 Lamarck 0 1 68 6 }
{0 1 9 The_Hoff 0 1 65 4 }
{0 2 8 Sir_Oppenheimer 0 1 62 6 }
```
