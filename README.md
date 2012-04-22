# PumpControl

## The problem

Our boiler and hot water tank are located in the garage at one end of the house, a long way from the taps in the bathrooms and kitchen. This means that we need to run the  tap for a minute or longer just to draw enough hot water through the pipes to get hot water at the tap. At 10 litres a minute this is a huge waste of water.

Because of this we have a hot water loop that runs under the floors. There is a pump which circulates water through this loop to keep it hot, and the taps draw off the loop, meaning we get hot water from the taps within a few seconds. However, we lose a lot of heat through that loop. Even lagged, the loop will go cold within about 20 minutes of the pump turning off.

## The solution

Instead of running the pump constantly, I would like to only run it when we actually need hot water. Next to each sink we would have a button which would kick the pump into action. Once the pump is running, the loop comes up to temperature within 20 to 30 seconds. We can stop the pump after a 30-60 seconds, leaving a loop full of hot water. As long as we continue to draw hot water, say running a bath or washing up, the loop will stay hot, and only cool down when we stop using it.

To achieve this, I have designed a system using an Arduino Uno and a Seeed Studio relay shield to turn the pump on and off in response to a signal. That signal is triggered using X10 RF switches and an X10 Universal Module. The Arduino is running the sketch in this project.

The sketch is quite simple: It looks to see if pin 12 goes high, which triggers the relay to supply power to the pump. After a set period of time (currently 60s), it turns the relay off to stop the pump. The sketch will then not respond to the input signal again for a set period of time (currently 5 minutes). During this time the loop will still be hot and there is no point running the pump again.