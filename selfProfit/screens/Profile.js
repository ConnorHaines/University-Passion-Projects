// screens/Profile.js

import React from 'react'
import { View, Text, StyleSheet, Button, Keyboard } from 'react-native'
import { TextInput, TouchableOpacity } from 'react-native-gesture-handler'


class Profile extends React.Component {
    state = {
        seincome : "",
        seexpenses:"",
        balance:0,
        NI2: 156,
        endTax: 0,
        disabled: false,
        empty: true
    }



    onChangeSEINCOME = (value) => {


        this.setState({
            disabled:false,
            seincome:value,
            empty:false

        })



    }


    onChangeSEEXPENSES = (value) => {

        this.setState({
            disabled:false,
            seexpenses:value,
            empty:false
        })



    }

    clear = () => {
        this.setState({
            seincome : "",
            seexpenses:"",
            balance:0,
            NI2: 156,
            endTax: 0,
            disabled: false,
            empty:true
        })
    }

    calculator = () => {
        const { seincome, seexpenses, NI2} = this.state

            var seprofit = seincome - seexpenses
            var tax = 0
            var taxableIncome = 0
            var highTax = 0
            var highTaxable = 0
            var superTax = 0
            var superTaxable = 0
            var totalTax = 0
            

            Keyboard.dismiss()
            this.setState({disabled:true})
            
            if(seprofit <= 6365){
                this.setState({
                  
                    balance: seprofit - totalTax 
                })
            }
            else if(seprofit >= 6365 && seprofit <= 12500  && seincome !="" ){

                
                this.setState({
                    endTax: totalTax,
                    balance: seprofit - totalTax - NI2 
                })

            }else if(seprofit >= 12501 && seprofit <= 50000){
                taxableIncome = (seprofit - 12500)

                tax = (taxableIncome * 0.20)

                totalTax = tax

                this.setState({
                    endTax: totalTax,
                    balance: seprofit - totalTax - NI2
                })


            }else if(seprofit >= 50001 && seprofit  <= 150000){

                highTaxable = (seprofit - 50000)
                highTax = (highTaxable * 0.40)

                taxableIncome = ((seprofit - highTaxable) - 12500)
                tax = (taxableIncome * 0.20)

                totalTax = highTax + tax


                this.setState({
                    endTax: totalTax,
                    balance: seprofit - totalTax - NI2
                })                


            }else if(seprofit >= 150001){

                superTaxable = (seprofit - 150000)
                superTax = (superTaxable * 0.45)

                highTaxable = ((seprofit - superTaxable) -50000)
                highTax = (highTaxable * 0.40)

                taxableIncome = ((seprofit - highTaxable) - 12500)
                tax = (taxableIncome * 0.20)

                totalTax = (superTax + highTax) - tax

                this.setState({
                    endTax: totalTax,
                    balance: seprofit - totalTax - NI2
                })  

                
            }


            

    }

    
    render() {


        return (
            <View style={styles.container}>
                {/* <Text>~UNDERCONSTRUCTION~</Text> */}
                <TextInput
                    style={styles.inputBox}
                    value={String(this.state.seincome)}
                    onChangeText={value => this.onChangeSEINCOME(value)}
                    placeholder='Insert Self Employed Income'
                    autoCapitalize='none'
                    keyboardType="numeric"
                    maxLength={Number("7")}
                />
                <TextInput
                    style={styles.inputBox}
                    value={String(this.state.seexpenses)}
                    placeholder='Insert Self Employed Expenses'
                    autoCapitalize='none'
                    onChangeText={value => this.onChangeSEEXPENSES(value)}
                    keyboardType="numeric"
                    maxLength={Number("7")}
                />

                <TouchableOpacity style={this.state.disabled? styles.disabled : styles.button}  onPress={this.calculator} disabled={this.state.disabled} >
                  <Text style={styles.buttonText}>CALCULATE</Text>
                </TouchableOpacity>

                <TouchableOpacity style={this.state.empty? styles.disabled : styles.button}  onPress={this.clear} disabled={this.state.empty} >
                  <Text style={styles.buttonText}>CLEAR</Text>
                </TouchableOpacity>

                    <Text>Your income is £{this.state.balance}.</Text>

                    <Text> After paying £{this.state.endTax} tax,</Text>

                    <Text>£{this.state.NI2} Class 2 NI.</Text>

                <Button title="Logout"
                onPress={() => this.props.navigation.navigate('Login')} />

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
        marginTop: 30,
        marginBottom: 20,
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
    disabled:{
        marginTop: 30,
        marginBottom: 20,
        paddingVertical: 5,
        alignItems: 'center',
        backgroundColor: '#ffb5b8',
        borderRadius: 5,
        width: 200,
    }

})

export default Profile