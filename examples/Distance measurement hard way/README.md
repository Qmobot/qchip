# Easy way to measure distance

## Usage

In the example you can find how to measure distance by manual function in "hard" way.

## Info

To measure distance to the object in front of the Qmobot, it uses two Ultrasonic distance measurement modules. We use two of them to navigate in space and SLAM.

> In navigation, robotic mapping and odometry for virtual reality or augmented reality, simultaneous localization and mapping (SLAM) is the computational problem of constructing or updating a map of an unknown environment while simultaneously keeping track of an agent's location within it.
>

Ultrasonic sensors work by emitting sound waves at a frequency too high for humans to hear. They then wait for the sound to be reflected back, calculating distance based on the time required. This is similar to how radar measures the time it takes a radio wave to return after hitting an object.

While some sensors use a separate sound emitter and receiver, it’s also possible to combine these into one package device, having an ultrasonic element alternate between emitting and receiving signals. This type of sensor can be manufactured in a smaller package than with separate elements, which is convenient for applications where size is at a premium.

While radar and ultrasonic sensors can be used for some of the same purposes, sound-based sensors are readily available—they can be had for just a couple dollars in some cases—and in certain situations, they may detect objects more effectively than radar.

For instance, while radar, or even light-based sensors, have a difficult time correctly processing clear plastic, ultrasonic sensors have no problem with this. In fact, they’re unaffected by the color of the material they are sensing.

On the other hand, if an object is made out of a material that absorbs sound or is shaped in such a way that it reflects the sound waves away from the receiver, readings will be unreliable.

If you need to measure the specific distance from your sensor, this can be calculated based on this formula:

``Distance = ½ T x C``

(T = Time and C = the speed of sound)

At 20°C (68°F), the speed of sound is 343 meters/second (1125 feet/second), but this varies depending on temperature and humidity.

Specially adapted ultrasonic sensors can also be used underwater. The speed of sound, however, is 4.3 times as fast in water as in air, so this calculation must be adjusted significantly.

So where can we use these sensors? Robot navigation comes to mind, as well as factory automation. Water-level sensing is another good use, and can be accomplished by positioning one sensor above a water surface. Another aquatic application is to use these sensors to “see” the bottom of a body of water, traveling through the water, but reflecting off the bottom surface below.

Though it might not be immediately obvious, if configured correctly ultrasonic sensors can even measure fluid flow rates. In the simplest case, an emitter and a receiver (separate in this configuration) are aligned with the flow of a fluid. Since sound is traveling through a moving medium, the speed of sound relative to these elements will be increased or decreased by the velocity of the fluid. This can be applied to flow inside pipes by aligning these two elements at an angle to each other, calculating the effective velocity increase based on the trigonometric relations between the two.

Flowrate accuracy can be increased by using data from multiple ultrasonic elements, giving results accurate to within a fraction of a percent.