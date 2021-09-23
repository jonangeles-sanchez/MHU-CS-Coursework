# CS220 - Data Structures
## Dynamic Queue Implmentation

### Phase 1 - Four (4) Basic Methods Plus Constructor
First, write the four (4) basic methods plus the constructor:
* `Queue()`
* `append()`
* `serve()`
* `retrieve()`
* `empty()`

There is a simpletest.cpp file you can use to see if your Queue works. To compile it,
type `make`. This will attempt to build an executable in your directory called `queue`.
Execute it by typing `./queue`.

You can also run some basic unit tests on your Queue. To compile/run the basic tests, type
`make basictest`. This will attempt to build an executable called `test`, which you can
run by typing `./test`. There are seven (7) tests that your code should pass before
submitting.

### Phase 2 - Advanced Methods
After submitting phase 1, **make sure your code is committed (git status)** and then run the `phase2` script by typing `./phase2`. This will reconfigure your configuration to prepare your code for phase 2.

For this phase, you will perform the following:
* Add the property `count` to your Queue class. Increment it and decrement it appropriately.
* Add the method `size()` to your Queue class.
* Add the safeguard methods:
  * Destructor
  * Overloaded assignment operator
  * Copy Constructor

You may use the simple test provided above, but it won't do a great job testing your Queue
for errors unless you augment it.

You can also run some advanced unit tests on your Queue. To compile/run the advanced tests, type
`make test`. This will attempt to build an executable called `test`, which you can
run by typing `./test`. Your code should pass all tests.
