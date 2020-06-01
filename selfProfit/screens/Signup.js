// screens/Signup.js

import React from 'react'
import { View, TextInput, StyleSheet, Alert, TouchableOpacity, Text, Button, Image, Platform} from 'react-native'
import Firebase from '../config/Firebase'

class Signup extends React.Component {
    state = {
        name: '',
        email: '',
        password: ''
    }
    handleSignUp = () => {
        const { email, password, name } = this.state

        
        if(email === "" || password ==="" || name === ""){
            Alert.alert("All fields need to be filled out!")
        }else{
        Firebase.auth()
            .createUserWithEmailAndPassword(email, password)
            .then(() => this.props.navigation.navigate('Tutorial'))
            .catch(error => console.log(error))

            
        }
    }

    render() {
        return (
            <View style={styles.container}>
                <Image source = {require("../assets/lighting.png")}
                style={{width:80, height:80}}/>
                <TextInput
                    style={styles.inputBox}
                    value={this.state.name}
                    onChangeText={name => this.setState({ name })}
                    placeholder='Full Name'
                />
                <TextInput
                    style={styles.inputBox}
                    value={this.state.email}
                    onChangeText={email => this.setState({ email })}
                    placeholder='Email'
                    autoCapitalize='none'
                />
                <TextInput
                    style={styles.inputBox}
                    value={this.state.password}
                    onChangeText={password => this.setState({ password })}
                    placeholder='Password'
                    secureTextEntry={true}
                />
            <TouchableOpacity style={styles.button} onPress={this.handleSignUp}>
                <Text style={styles.buttonText}>Signup</Text>
            </TouchableOpacity>
            <TouchableOpacity
                style={{color:"red"}}
                onPress={() => this.props.navigation.navigate('Login')} >

                    <Text style={styles.linkText}>Already have an account? Log in</Text>
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
        justifyContent: 'center',
        backgroundColor:"#FCE77D",
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
        fontSize: 20,
        fontWeight: 'bold',
        color: "#FCE77D",
        fontFamily: (Platform.OS === 'android' ? 'sans-serif' : 'American Typewriter')    },
    buttonSignup: {
        fontSize: 12
    },
    linkText:{
        color:"#F96167",
        fontFamily: (Platform.OS === 'android' ? 'sans-serif' : 'American Typewriter'),
        fontSize:16,
        marginTop:15,
        height:40,
        padding: 10
    }
})

export default Signup