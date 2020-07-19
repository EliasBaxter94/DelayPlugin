# Working with the JSUI


1. You need to build blueprint's juce-blueprint JS module. In terminal cd to the juce-blueprint module:

     `cd DelayPlugin/blueprint/packages/juce-blueprint`

   Now you need to pull the npm packages that juce-blueprint needs to build:

     `npm install`

   Now you need to run the juce-blueprint build command:

     `npm run build`


2. You now need to build you DelayPlugin's JSUI app. In terminal jump into the jsui dir:

    `cd DelayPlugin/Source/jsui`

   Fetch the npm packages needed:

     `npm install`

   Now run the jsui build step:

     `npm run build`


3. Now you can hit build in your Xcode project as normal.


4. To "live code" or "hot-reload" you need to be running the webpack watch task in the jsui directory.
   With you project running under xcode run the following set of commands in terminal:

     `cd DelayPlugin/Source/jsui`

     `npm run watch`

   After running the `npm run watch` command webpack will begin watching all of your JS files for changes.
   With your app running in debug mode under xcode you can edit any JS file in the jsui directory and the changes
   will be instantly reloaded in your app without needed to stop xcode and recompile. Xcode support for JS is
   pretty much non-existent so your best running XCode and VSCode side by side and editing your Javascript
   in VSCode. Open VSCode with `DelayPlugin/Source/jsui` at the root.



## Debugging your JS/JSUI code in VsCode.


It is possible to debug your Javascript code using VSCode. Note you cannot set breakpoints and debug your
javascript code from XCode. To set this up you simply need to install the duktape debugger extension for
VsCode:

    https://marketplace.visualstudio.com/items?itemName=HaroldBrenes.duk-debug

To run a debug session, click on your DelayPlugin UI whilst it is running under XCode to give the UI keyboard
focus. Now pres CMD-d to have the DelayPlugin JSUI wait for a debugger to attach (you'll notice you cannot interact
with the UI now until you attach a debugger.

To attach the debugger open VsCode and open the jsui directory, go to the debug menu on the left of VsCode and
hit the play icon in top toolbar.


## Useful resources when working on your JSUI:

	Guide to flexbox layout:
	https://css-tricks.com/snippets/css/a-guide-to-flexbox/
