// screens/Profile.js

import React from 'react'
import { View, Text, StyleSheet, Button, TouchableOpacity, Image, Platform } from 'react-native'
import { TextInput } from 'react-native-gesture-handler'
import MapView, { Polyline, PROVIDER_GOOGLE } from 'react-native-maps'
import * as Permissions from 'expo-permissions'
import * as Location from 'expo-location'
import haversine from 'haversine';

class RouteTracker extends React.Component {
  constructor() {
    super()
    this.state = {
      currentLocation: { lat: null, lng: null },
      coordinates: [],
      routeCoordinates: [],
      distanceTravelled: 0, 
      prevLatLng: {},
      LATITUDE_DELTA: 0.009,
      LONGITUDE_DELTA: 0.009,
      isMapReady: false,
      tracking: false,
      errorMessage: '',
    }
  }

  componentDidMount() {
    this._getLocationAsync();
  }

  _getLocationAsync = async () => {

    let { status } = await Permissions.askAsync(Permissions.LOCATION);
    if (status !== 'granted') {
      this.setState({
        errorMessage: 'Permission to access location was denied',
      });
    }
    let location = await Location.getCurrentPositionAsync({});
    this.setState({
      coordinates: [{
        latitude: location.coords.latitude,
        longitude: location.coords.longitude,
        latitudeDelta: this.state.LATITUDE_DELTA,
        longitudeDelta: this.state.LONGITUDE_DELTA

      }],
      currentLocation: { lat: location.coords.latitude, lng: location.coords.longitude },
    });
  }

  reset = () => {
    this.setState({
      currentLocation: { lat: null, lng: null },
      coordinates: [],
      routeCoordinates: [],
      distanceTravelled: 0, 
      prevLatLng: {},
      LATITUDE_DELTA: 0.009,
      LONGITUDE_DELTA: 0.009,
      isMapReady: false,
      tracking: false,
      errorMessage: '',
    }, () => this._getLocationAsync())
}


  startTracking = async () => {
      let index = 0;
      while(this.state.tracking){
        if(this.state.routeCoordinates[index-1] !== undefined){
          this.setState({prevLatLng: this.state.routeCoordinates[index-1]})
        }
          let update = await Location.getCurrentPositionAsync();
          this.setState({routeCoordinates: [...this.state.routeCoordinates, { latitude: update.coords.latitude, longitude: update.coords.longitude }]},
            () => {
                this.setState({distanceTravelled: this.state.distanceTravelled + this.calcDistance({ latitude: update.coords.latitude, longitude: update.coords.longitude })})
          })
        await this.interval(1000)
        index++;
      }
  }

  interval = async (ms) => {
    return new Promise(resolve => setTimeout(resolve, ms))
  }

  stopTracking = () => {
    this.setState({ tracking: false})
  }

  calcDistance = newLatLng => {
    return haversine(this.state.prevLatLng, newLatLng, {unit: 'meter'});
  };

  onMapLayout = () => {
    this.setState({ isMapReady: true });
  }

  render() {
    let text = 'Waiting..';
    let text2 = null;
    if (this.state.errorMessage) {
      text = this.state.errorMessage;
    } else if (this.state.location) {
      text = JSON.stringify(this.state.location.coords.longitude);
      text2 = JSON.stringify(this.state.location.coords.latitude);
    }
    const {currentLocation, isMapReady, routeCoordinates, LATITUDE_DELTA, LONGITUDE_DELTA } = this.state;
    const GOOGLE_MAPS_APIKEY = 'AIzaSyCyWLrZxvtMmCQDWq49lZeaWEhIU6a324k'
    return (
      <View style={styles.container}>
        {
          routeCoordinates.length || currentLocation.lat ?
            < MapView
              provider={PROVIDER_GOOGLE}
              style={styles.mapStyle}
              region={
                routeCoordinates && routeCoordinates.length ?
                  {
                    ...routeCoordinates[routeCoordinates.length - 1],
                    latitudeDelta: LATITUDE_DELTA,
                    longitudeDelta: LONGITUDE_DELTA
                  }
                  :
                  {
                    latitude: currentLocation.lat,
                    longitude: currentLocation.lng,

                    latitudeDelta: LATITUDE_DELTA,
                    longitudeDelta: LONGITUDE_DELTA,
                  }
              }
              onLayout={() => { this.onMapLayout() }}
            >
              {isMapReady ?
                <MapView.Marker
                  coordinate={
                    routeCoordinates && routeCoordinates.length ?
                      routeCoordinates[routeCoordinates.length - 1]
                      :
                      {
                        latitude: currentLocation.lat,
                        longitude: currentLocation.lng,
                      }
                  }
                />
                :
                null
              }
              {isMapReady ?
                <Polyline
                  coordinates={routeCoordinates}
                  strokeColor="green"
                  strokeWidth={3}
                />
                :
                null
              }
            </MapView >
            : null
        }
        {
          !this.state.tracking && this.state.distanceTravelled > 0
            &&
          <Text>{"\n"}You have travelled {((this.state.distanceTravelled)/1000).toFixed(3)} Km {"\n"}Calculating from Gov.uk website,{"\n"}you can charge back: £{((this.state.distanceTravelled)/1000).toFixed(3) * 0.30}</Text>
        }

        {this.state.tracking && <Text>Tracking on</Text>}
        <TouchableOpacity style={[styles.button, {opacity: (this.state.tracking ? 0.2 : 1)}]} disabled={this.state.tracking}
          onPress={() => {this.setState({tracking: true, prevLatLng: {latitude: this.state.currentLocation.lat, longitude: this.state.currentLocation.lng}}, () => this.startTracking())}}
        >
          <Text style={styles.buttonText}>START</Text>
        </TouchableOpacity>

        <TouchableOpacity style={[styles.button, {opacity: (!this.state.tracking ? 0.2 : 1)}]} disabled={!this.state.tracking}
          onPress={() => {this.stopTracking()}}
        >
          <Text style={styles.buttonText}>STOP</Text>
        </TouchableOpacity>

        <TouchableOpacity style={styles.button}
          onPress={this.reset}
        >
          <Text style={styles.buttonText}>RESET</Text>
        </TouchableOpacity>
      </View>
    )
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center'
  },
  inputBox: {
    flex: 1,
    width: '85%',
    margin: 10,
    padding: 15,
    fontSize: 16,
    borderColor: '#F96167',
    borderBottomWidth: 2,
    textAlign: 'center',
    backgroundColor: "white"
  },
  button: {

    marginTop: 30,
    marginBottom: 20,
    paddingVertical: 5,
    alignItems: 'center',
    backgroundColor: '#F96167',
    borderColor: '#F6820D',
    borderWidth: 1,
    borderRadius: 5,
    width: 200,


  },
  buttonText: {
    color: "white",
    fontFamily: (Platform.OS === 'android' ? 'sans-serif' : 'American Typewriter')


  },
  mapStyle: {
    height: 380,
    width: 380,
    borderColor: '#F6820D',
    borderWidth: 2,
    borderRadius: 5
  },
})

export default RouteTracker