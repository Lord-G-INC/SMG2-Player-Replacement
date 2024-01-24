# SMG2-Player-Replacement
A mod that allows replacing Mario's model.

***Note:*** This code patch is in very early development. Changes can and will be made, and things may or may not break.

## How to use
1. Head over to the Releases tab and download the latest `PlayerFollowActor.arc` and `pfa.xml` files.
2. Open the arc file with a tool like [WiiExplorer](https://github.com/SuperHackio/WiiExplorer/releases/tag/V1.5.0.5) and add in:
   - A `PlayerFollowActor.bdl` file, which can be any model you like.
   - *Optionally:* Some `.bck` animation files. To see which animations you can add, check `MarioAnime.arc`.
3. Save the file in your `ObjectData/` directory.
4. The xml file contains Riivolution memory patches, which you can simply add to an existing xml file or make a new one.
5. Boot up the game and enjoy!

## How to build
If you want to build this code yourself, you will need to download [Syati](https://github.com/SMGCommunity/Syati/) and its dependencies.

Then, clone this repo and paste the files into the Syati folder.

Run `build.py` and enjoy!
