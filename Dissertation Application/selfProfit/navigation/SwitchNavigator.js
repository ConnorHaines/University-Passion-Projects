import React from 'react'
import { createAppContainer,  } from 'react-navigation';
import { createStackNavigator } from 'react-navigation-stack';
import { createMaterialTopTabNavigator } from 'react-navigation-tabs';
import Login from '../screens/Login'
import Signup from '../screens/Signup'
import Profile from '../screens/Profile'
import RouteTracker from '../screens/RouteTracker'
import Tutorial from '../screens/Tutorial'
import { View, Platform } from 'react-native';


const SwitchNavigator = createStackNavigator(
    {
    Login: {
        screen: Login,
        navigationOptions: ({ navigation }) => ({
            header: <View style={{marginTop: 0}} />
          }),
      },
      Signup: {
        screen: Signup,
        navigationOptions: ({ navigation }) => ({
            header: <View style={{marginTop: 0}} />
          }),
      },
      Tutorial: {
        screen: Tutorial,
        navigationOptions: ({ navigation }) => ({
            header: <View style={{marginTop: 0}} />
          }),
      },
      Profile: {
        screen: createMaterialTopTabNavigator({
          Profile: {
            screen: Profile,
            navigationOptions: ({ navigation }) => ({
              tabBarLabel: 'Tax & NI',
              tabBarOptions: {
                  labelStyle: {
                    color: '#FCE77D',
                    fontFamily: (Platform.OS === 'android' ? 'sans-serif' : 'American Typewriter')                    

                  },
                style: {
                    backgroundColor: '#F96167'
                }
            }
            }),
          },

          RouteTracker: {
            screen: RouteTracker,
            navigationOptions: ({ navigation }) => ({
              tabBarLabel: 'RouteTracker',
              tabBarOptions: {
                labelStyle: {
                  color: '#FCE77D',
                  fontFamily: (Platform.OS === 'android' ? 'sans-serif' : 'American Typewriter')

                },
              style: {
                  backgroundColor: '#F96167'
              }
          }
              
            }),
          },
        }),
        navigationOptions: ({ navigation }) => ({
          title: 'Profile',
          header: <View style={{height: 30, width: '100%', backgroundColor: '#F96167'}} />,
            
        }),
      },
    })

export default createAppContainer(SwitchNavigator)