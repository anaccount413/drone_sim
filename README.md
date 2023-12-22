This project is a 3D simulation of a system for delivering packages with the use of drones.

The simulation provides features such as camera movement (e.g. focusing the camera on an entity), simulation speed adjustment, and route visualization.

The simulation allows package generation, automatically scheduling the packages/deliveries once a package and corresponding robot owner is created. The scheduling page provides a variety of customization, including choosing a routing algorithm and other features described in the “What does the simulation do specifically?” section. The simulation then simulates how drones move to, pick up, and deliver these packages.

Upon successful delivery, the drone will complete a celebration based on the routing algorithm that was used, such as jumping up and down or spinning. As a specific example, the drone will spin for some time, then jump for some time after completing an order using Dijkstra’s.

It will then repeat these actions for the rest of the packages in the delivery queue.

Finally, there are also additional entities such as helicopters and humans for realism. Helicopters repeatedly choose random destination points and travel to their destination using a beeline strategy, while humans choose random destinations and travel using A*. Additional humans can be added from the scheduling page.

