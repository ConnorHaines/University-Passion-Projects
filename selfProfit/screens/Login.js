import React from 'react'
import { View, TextInput, StyleSheet, TouchableOpacity, Alert, Text, Button, Image, Animated, Platform } from 'react-native'
import Firebase from '../config/Firebase'
class Login extends React.Component {
    state = {
        email: '',
        password: ''
        
    }
    
    handleLogin = () => {
        const { email, password } = this.state

        if(email === "" && password ===""){
            Alert.alert("Both fields need to be filled out!")
        }else if(password === ""){
            Alert.alert("Password field need to be filled out!")
        }else if(email === ""){
            Alert.alert("Email field need to be filled out!")
        }else if(email != "" && password != ""){

            Firebase.auth()
            .signInWithEmailAndPassword(email, password)
            .then(() => this.props.navigation.navigate('Profile'))
            .catch(error => console.log(error))

            setTimeout(() => {

            this.setState({
                email: '',
                password: ''
            })
            }, 2000);

        }


    }

    UNSAFE_componentWillMount(){
        this.animatedValue = new Animated.Value(0);
    }

    componentDidMount(){
        Animated.timing(this.animatedValue,{
            toValue: 150,
            duration:2500
        }).start();
    }

    render() {

        const interpolateColor = this.animatedValue.interpolate({
            inputRange: [0,150],
            outputRange: ['#F96167', '#FCE77D']
        })

        const animatedStyle ={
            backgroundColor: interpolateColor
        }

        return (
            <Animated.View style={[styles.container, animatedStyle]}>
                <Image source = {require("../assets/lighting.png")}
                style={{width:80, height:80}}/>
                <Text style={styles.brandname}>SelfProfit</Text>
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
                <TouchableOpacity style={styles.button} onPress={this.handleLogin}>
                    <Text style={styles.buttonText}>Login</Text>
                </TouchableOpacity>
                <TouchableOpacity 
                
                onPress={() => this.props.navigation.navigate('Signup')} >
                   <Text style={styles.linkText}> Don't have an account yet? Sign up </Text>
                    </TouchableOpacity>
            </Animated.View>
        )
    }
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: "#FCE77D",
        alignItems: 'center',
        justifyContent: 'center'
    },
    brandname:{
        fontFamily: (Platform.OS === 'android' ? 'sans-serif' : 'American Typewriter'),
        fontWeight:"600",
        fontSize: 50,
        color: "#F96167",
        marginBottom:14,

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
        borderColor: '#F96167',
        borderWidth: 1,
        borderRadius: 5,
        width: 200
    },
    buttonText: {
        fontSize: 20,
        fontWeight: 'bold',
        color: "#FCE77D",
        fontFamily: (Platform.OS === 'android' ? 'sans-serif' : 'American Typewriter'),
    },
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

export default Login
