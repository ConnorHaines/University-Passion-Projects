// screens/Tutorial.js

import React from 'react'
import { View, Text, StyleSheet, Button, Keyboard } from 'react-native'
import { TextInput, TouchableOpacity } from 'react-native-gesture-handler'


class Tutorial extends React.Component {
    state = {
        
    }

    render() {


        return (
            <View style={styles.container}>
               <Text style={styles.brandname}>1.Tax Calculator</Text>
               <Text>The Tax Calculator is the first page in the app.</Text>
               <Text>To use it, input your overall income and</Text>
               <Text style={styles.endtext}>your expenses in the correct boxes and click 'calculate'.</Text>
               <Text style={styles.brandname}>2.Route Tracker</Text>
               <Text>To get to the Route Tracker, swipe left.</Text>
               <Text>Once you are ready to start tracking, click 'Start'.</Text>
               <Text style={styles.endtext}>To see distance travelled, click 'Stop'.</Text>

                <TouchableOpacity style={styles.button}  onPress={() => this.props.navigation.navigate('Profile')} >
                  <Text style={styles.buttonText}>CONTINUE</Text>
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
        width: '85%',
        margin: 10,
        padding: 15,
        fontSize: 16,
        borderColor: '#F96167',
        borderBottomWidth: 2,
        textAlign: 'center',
        backgroundColor:"white"
    },
    button: {
        marginTop: 60,
        marginBottom: 0,
        paddingVertical: 5,
        alignItems: 'center',
        backgroundColor: '#F96167',
        borderRadius: 5,
        width: 200,
        
    
    },
    buttonText:{
        color:"white",
        fontFamily: (Platform.OS === 'android' ? 'sans-serif' : 'American Typewriter')

    },
    brandname:{
        fontFamily: (Platform.OS === 'android' ? 'sans-serif' : 'American Typewriter'),
        fontWeight:"600",
        fontSize: 35,
        color: "#F96167",
        marginBottom:19,

    },
    endtext:{
        marginBottom:100,

    },

})

export default Tutorial