# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## PID Controller Introduction
PID Controller stands for Propotional-Integral and Differential Controller in which it can be defined as a feedback control loop. It is most commonly used in many applications related with control systems. It depends on error value which can be calculated by the difference between a desired setpoint value and variable measured process. The PID Controller applies its components (P, I and D) to control the whole process by: decrease the calculated error as most as possible, and achieve approximately the same setpoint for the variable measured.
 
![alt text](pid.jpg "PID Controller")

In this Project, PID controller is applied on autonomous driving application. Udacity Simulator is responsible for calculating the error signal: difference between the actual car position on the road and the reference trajectory. This is why this error is named by Cross-Track Error (CTE). In addition to this error, we have current speed value. It is desired to design a PID controller to control the steering angle of the car.  

## PID Components Effect

##### The Propotional Component (P)
It is the most important component in the controller as the most effectibe component on the steering angle. It is responsible for having an opposite effect of the CTE. This means that if the CTE is positive, the P component shoulf have a negative steering command, and vice versa.

##### The Integral Component (I)
This component will take the accumulated error (CTE) over the past time  into its consideration. It corrects systematic bias and constant deviation which can prevent the controller from reaching the center of the reference trajectory. 

##### The Differential Component (D)
This component is proportional to the rate of change of the error (CTE). It has a great effect on reducing the overshooting or the oscillations caused by the propotional component (P).


## PID Controllers Project
It was desired to control the steering angle of the car using the CTE. Actually I have created **Two PID Controllers**: the first one for steering by depending on the CTE from the simualtor, and the second one for throttle by depending on the Speed from the simulator. 

The input to Steering angle PID controller is the CTE, and my aim is to reduce this CTE as possible, so I designed the PID Controller using manual tunning for its paramaters as follows:

| Steering PID Controller  | Component Values  |
|:-------------------------:|:-------------------------:|
| P              |       0.09        |
| I              |      0.0014       |
| D              |        1.4        |

The input to the throttle PID controller is the error of a desired speed and the speed calculated by the simulator, and my aim is to reach to this target speed as possible, so I designed the PID Controller using manual tunning for its paramters (taking into consideration achieve a higher speed target value) as follows:

| Steering PID Controller  | Component Values  |
|:-------------------------:|:-------------------------:|
| **Target Speed**              |       **50**        |
| P              |       0.1        |
| I              |        0       |
| D              |        0        |


## Hyperparameters Tuning
I have tuned the two PID Controllers manually:

* Steering angle PID controller parameters are tuned by firstly tune the P-component, after that tune the D-component by slight increasing gradually in order to remove the whole overshoots or oscillations, and finally add small value for the integral and this value can be zero as it doesn't have a great effect on the car motion. This is due to, in this application, the steering drift is very small in the simulator.

* Throttle PID Controller parameters are tuned by using only the P-Component as it will help in reaching to the desired or target speed value as fast as possible without the need of the other components either: I-Component or D-Component.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

