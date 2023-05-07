# C-Trials-
# Ideas for stuff i'd like to try out and implement

## Idea One: Super Mario Brothers:
- Original design and implementation meant to be done with python, ansd should be available [here]() soon 
## Goals:
### Player(Mario) should be able to:
1. Move around in a 2D environment, in up, down left and right directions
2. Move in a consistent and regulated speed throughout the game, and process special commands : ie " Double Jump"
3. Collect materials and coins as he progresses through the game.

### The environment he will move in should be able to:
1. Contain obstacles that allow him to utilize all ranges of motion ( Up, Down , Left and right) 
2. Contain coins, powerups and trigger points for next levels/ new enemies/ other easter eggs.
3. Change background position as the player moves through the environment.

### Powerups:
1.  The powerups to be implemented must only augment a property  already posessed by  the player , and like so :
```
class Powerup {
public:
    virtual void activate(Player& player) = 0;
};

class StrengthBoost : public Powerup {
public:
    virtual void activate(Player& player) {
        // Increase the player's strength by 10
        player.strength += 10;
    }
};

class Player {
public:
    int strength;
    // Other stats here

    void activatePowerup(Powerup& powerup) {
        powerup.activate(*this);
    }
};

```

or with python:
```
class Powerup:
    def activate(self, player):
        pass

class StrengthBoost(Powerup):
    def activate(self, player):
        # Increase the player's strength by 10
        player.strength += 10

class Player:
    def __init__(self):
        self.strength = 50
        # Other stats here

    def activate_powerup(self, powerup):
        powerup.activate(self)

player = Player()
boost = StrengthBoost()
player.activate_powerup(boost)
print("Player strength after boost: ", player.strength)
# Output: Player strength after boost: 60

```

<span style="color:red">some **NOTE: This is not an exact implementation of the syntax, it is merely for demonstration porposes** text</span>

<p>Some Markdown text with <span style="color:blue">some <em>blue</em> text</span>.</p>
2. It could be one property, or a combination of properties that could be changed when activated
