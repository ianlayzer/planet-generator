# Planet Generator

### Introduction to Computer Graphics, Fall 2021
### Ian Layzer and Mikey Abela

## Introduction
This is a C++ / OpenGL application developed in QT Creator for procedurally generating
planets using simplex noise. The intention for this application is that it may be used
by 3D artists/game developers who may require a number of attractive and varied planets
for their artwork or game. With this system, they can quickly create planets with different
styles, color schemes, levels of resolution, and more.

## How to use it
Make sure that your resolution setting is not too high as this may createlag in the rendering 
of your planet. We recommend that you set the resolution to ~100 while you play around with the settings. You can also use the bottom toggle button that reads "One face only" to render only one side of your planet, toggle off 'Planet rotation', and/or toggle off "Smooth colors" to prevent interpolation between color values at different elevation levels, each of which should improve performance. Once you're happy with your settings, set the resolution as high as you like to see your planet in all its glory.

The Noise tab widget lets you adjust the noise layers for Continents, Mountains, and Oceans, respectively. The options available to you for each are largely the same, and allow you to create up to 8 layers of Simplex Noise to comprise that level of terrain. 
  - Strength acts as a scalar multiplier to the overall elevation value for each point.
  - Num Layers determines the total number of layers of Simplex Noise for the terrain level.
  - Base roughness is the initial frequency for the noise
  - Roughness is a scalar multiplier applied to frequency at each iteration of the loop through the layers of noise
  - Persistence is a scalar multiplier applied to amplitude (which starts at 1) at each iteration of the loop through the layers of noise
  - Min Value is used to clamp oceans - increasing this value will cause the terrain level to recede into the layer beneath it. (or the layer above it in the case of Oceans)
  - The Center X, Y, Z dials may be used to change the centroid of the noise.

Each terrain level may be toggled on and off with the 'Enabled' checkbox and the Mountain level has the option to use the Continents level as a mask, which will prevent mountains from generating anywhere other than on top of a continent (or in some cases in shallow ocean levels). Continents by default appear atop only shallow ocean levels, not deep ocean levels.

Note that Oceans, even though they have the same parameters as the other levels, act a bit differently. Toggling the settings for Oceans does procedurally generate depth for the ocean, but it does not change the elevation on the planet sphere. Ocean depth is used only for shading.

Once you have your terrain as you like it, you can add color! Ocean color is used as shallow ocean values and is automatically darkened to determine deep ocean color. Shore color is for the lowest terrain elevation above 0 (beaches). Land color is used for low-elevation land and is automatically darkened for slightly higher level terrain. Mountain color and mountain cap color are for the highest elevation levels. The thresholds for each elevation level are fixed in the planet vertex shader. With smooth colors enabled, the color for a vertex is determined by linearly interpolating between the two color thresholds that it is between.





