#include <stdio.h>
#include <math.h>

/*
OK I want to make a neural net in C so let me get a check list

* Input data
* Weights
* Bias
* Output
* Activation function
* Error calculation
* Backprop

* So i have no idea how to insert data into the model or what kind of data for that matter... future problem i guess.
* I am going to use the sigmoid activation function because that is the function that I understand the best. Maybe I will implement soft sigmoid in the future?
* Weights and biases I could store in a struct, weights as a array and bias could be a singlr value.
* Error calculation... mean square error i guess, that's the one i know properly. I kinda want to implement cross entropy in the future. 3blue1brown has a video on that.
* Output I beleive would be straight forward, It would be the value the last neuron would give after passing throught the activation function.
* Backprop, ok this I have no fuckin clue on how to do I know it uses the chain rule, how the fuck am i supposed to implement that in code! I guess I could apply a
  limit of sorts I believe the formula was ~~f(h) = (f(x) + f(x + h)) / h~~, but this is off the top of my head so I could be wrong (It is wrong).
  Update: the formula was wrong it was f(x) = (f(x + h) - f(x)) / h, where h tends to infinity.
*/

//A neuron contains its weight, bias and the number of inputs going into it.
typedef struct{
    double *weight;
    double *bias;
    double *z;
    double *activated;
    double *delta;
    int NumberofInput;
    int NumberofOutput;
}Layer;

typedef struct{
    int NumberofLayer;
    Layer *layers;
}NeuralNet;

//Sigmoid activation function, straight forward to implement.
double sigmoid(double out){
    return 1.0 / (1.0 + exp(-out));
}

double mean_square_error(double *out_pred, double *out_real, int NumberofInput){
    double error = 0.0;
    for(int i = 0; i < NumberofInput; i++){
        error += pow(out_pred[i] - out_real[i], 2);
    }
    return error / NumberofInput;
}

double regression(Layer *neuron, float *input, int NumberofInput){
    double out = 0.0;
    for(int i = 0; i < NumberofInput; i++){
        out += neuron->weight[i] * input[i] + neuron->bias[i];
    }
    return out;
}

double gradient_descent(Layer *neuron, double error){
    //code
}

/*
Tf am I going to make a network from individual neurons. Not to mention neural nets have multiple hidden layers. I guess i can start out with a single layer.
How do I know how many neurons does a single layer need? With this architecture I would need to manually setup each layer let alone each neuron! Should I refactor
or should write a function for this? fffffuckkkkkkk pen and paper implementation was easier than this.
*/
int main(){
    //code
    return 0;
}