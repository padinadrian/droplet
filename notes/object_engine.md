Object engine:

* Every object consists of:
    * Object ID (0-255)
    * Position (UINT8 x, UINT8 y)
    * State (0-255)
* On every frame the engine will run through the list of objects to update them.
* The Object ID tells the engine what kind of object this is. This is used in a
  lookup table to pick a callback where the object is passed to. The callback
  is specific to each object and contains the logic needed to do whatever actions
  this object does.
*

Hitboxes
* A hitbox is just a pair of coordinates that describe two opposite corners of a rectangle
* If the rectangles intersect, the two hitboxes are touching.
* This can be used to model object interaction - for example, if a player and enemy have hitboxes that are touching, the enemy is touching the player and that can trigger an event.

For wall collision:
* Instead of using the background tiles directly, keep a list of walls as hitboxes.
* A hitbox is just
* They don't need to be objects since they don't move.
*