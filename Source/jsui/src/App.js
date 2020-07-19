import React, { Component } from 'react';
import {
  View,
  Text,
} from 'juce-blueprint';

import { Colors } from './Constants'
import Slider from './Slider'
import Label from './Label'
import ParameterToggleButton from './ParameterToggleButton'


class App extends Component {
  render() {
    return (
      <View {...styles.container}>
        <View {...styles.content}>
          <View {...styles.header_content}>
            <Text {...styles.header_text}>
              Delay Plugin
            </Text>
          </View>
          <View {...styles.sliders_content}>
            <View {... styles.slider_content}>
              <Slider paramId="DelayTime" {...styles.slider}>
                <Label paramId="DelayTime" {...styles.slider_value_label} />
              </Slider>
              <Text {...styles.slider_name_label} {...styles.text}>
                Delay Time
              </Text>
            </View>
            <View {... styles.slider_content}>
              <Slider paramId="DelayDryWet" {...styles.slider}>
                <Label paramId="DelayDryWet" {...styles.slider_value_label} />
              </Slider>
              <Text {...styles.slider_name_label} {...styles.text}>
                Dry/Wet
              </Text>
            </View>
          </View>
          <View {...styles.buttons_content}>
            <ParameterToggleButton {...styles.button}>
              <Text {...styles.text}>Sync</Text>
            </ParameterToggleButton>
          </View>
        </View>
      </View>
    );
  }
}

const styles = {
  container: {
    'width': '100%',
    'height': '100%',
    'background-color': 'ff17191f',
  },
  content: {
    'flex': 1.0,
    'flex-direction': 'column',
    'justify-content': 'center',
    'align-items': 'center',
  },
  header_content: {
    'justify-content': 'center',
    'align-items': 'center',
    'height': "10%"
  },
  header_text: {
    'font-size': 20.0,
    'line-spacing': 1.6,
    'color': 'ff626262'
  },
  sliders_content: {
    'justify-content': 'space-around',
    'width': '100%',
    'height': "60%"
  },
  slider_content: {
    'flex': 1.0,
    'flex-direction': 'column',
    'justify-content': 'center',
    'align-items': 'center',
  },
  slider: {
    'min-width': 100.0,
    'min-height': 100.0,
    'height': '50%',
    'width': '50%',
  },
  slider_value_label: {
    'flex': 1.0,
    'justify-content': 'center',
    'align-items': 'center',
    'interceptClickEvents': false
  },
  slider_name_label: {
    'justify-content': 'center',
    'align-items': 'center',
    'interceptClickEvents': false
  },
  buttons_content: {
    'width': "100%",
    'align-items': 'center',
    'justify-content': 'space-around',
    'height': "20%"
  },
  text: {
    'font-size': 18.0,
    'line-spacing': 1.6,
    'color': 'ff626262',
  },
  button: {
    'height': '100%',
    'justify-content': 'center',
    'align-items': 'center',
    'aspect-ratio': 1.0,
    'border-width': 2.0,
    'border-color': Colors.STROKE,
    'border-radius': '20%',
  },
};

export default App;
