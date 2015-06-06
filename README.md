# Sensor Party Music Project 

Can robots play music you like? http://www.fastcolabs.com/3029276/can-robot-musicians-play-songs-that-entrance-human-ears … - can computers evolve music you like? My friend Michael Bauer (aka @mihi-tr) hopes so! And he told @rebekahmonson @ericcades and me (@miguelpaz) about his great idea of using sensors to identify what type of music people like more in the dancefloor. All of this during a Chicas Poderosas Miami event (http://www.meetup.com/Chicas-Poderosas/events/170403192/). 

Hence: Sensor Party Music Project... a evolving brainstorm on how to use sensors to create the ultimate dance music experience in a Sensor Party near you. 

## The Idea

Genetic algorithms are fantastic - based on scoring mechanisms they are
able to create something you would never have thought of. This works for
strategies for performing tasks, design of objects and many more areas.
Does it work for dance music? We hope so.

Imagine a party where you arrive, put on a sensor (or start an app on your
phone) and listen to quite experimental music. You might start to dance a
bit at one point and the music becomes more and more dancable - still very
experimental though. After a few hours it still will be quite experimental
but good and danceable. Machines learned what makes good dance music and
generate it. 

Every party will be different - based on mutations and randomness. Unique
but thrilling.

## How we can build it

Work on Genetic Algorithms to produce music using OpenFrameworks (the latter can also be used to read in the
sensor)

Then figure out how to do sensors - use mobile phones with an app that
reads the accelerometers. This can help us getting off cheap. Otherwise
create wrist-bands that radio in the movements. 

Connect the two / test+iterate: Win!

## Be Part of it!

The Sensor Party Music Project is a creative, collaborative effort. Just as
we collaboratively want to create music on the event you can be part of
this.

How:

* Contribute Code - Fork us on Github and figure out how to do parts
* Share your ideas: In issues or on the wiki!
* Test and review what is already there.

## Using

The spmproject repository is designed to be cloned into the ```apps```
subdirectory of your [OpenFrameworks](http://openframeworks.cc) folder.
Currently the files are layed out for code::blocks on linux. If you work
with Xcode or on Windows - feel free to add project files to help
development accross platforms.

Since code::blocks works with makefiles you could also just install all the
neccessary tools and call ```make```.

## Requirements

You'll need the [Sonatina Symphony Orchestra](http://sso.mattiaswestlund.net/) 
samples unpacked in the ```data``` folder inside the ```bin``` subfolder
once your project is built. These are the samples currently used. Check
```samples.txt``` for the exact files.

Of course you could use different samples and edit the ```samples.txt```
file accordingly.
