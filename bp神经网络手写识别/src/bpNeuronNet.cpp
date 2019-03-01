#include "bpNeuronNet.h"

bpNeuronNet::bpNeuronNet()
{
    //ctor
}

bpNeuronNet::~bpNeuronNet()
{
    //dtor
}

double bpNeuronNet::sigmoidActive(double activation, double response)
{/** reponse 是用于缩放 activation的，取值范围： 0 < response <= 1.0 */
    /** sigmoid function: f(x) = 1 /(1 + exp(-x)) */
    return (1.0 / (1.0 + exp(-activation * response)));
}

void bpNeuronNet::updateNeuronLayer(neuronLayer& nl, const double inputs[])
{
    int numNeurons = nl.mNumNeurons; /** 当前层有多少个神经细胞 */
    int numInputsPerNeuron = nl.mNumInputsPerNeuron; /** 当前层的每一个神经细胞有多少输入 */
    double* curOutActivations = nl.mOutActivations; /** 当前层所有神经细胞的输出值数组 */

    /** 遍历每一个神经细胞 */
    for (int n = 0; n < numNeurons; ++n)
    {
        double* curWeights = nl.mWeights[n]; /** 获取第n个神经细胞的输入权重数组 */

        double netinput = 0;
        int k;
        /** 遍历每一个输入权重 */
        for (k = 0; k < numInputsPerNeuron; ++k)
        {
            /*** 累加 weights 和 inputs的乘积 */
            netinput += curWeights[k] * inputs[k];
        }

        /** 添加偏置项的值 */
        netinput += curWeights[k] * BIAS;


        /** 将累加后的值通过激活函数，得到当前神经细胞的最终输出 */
        curOutActivations[n] = sigmoidActive(netinput, ACTIVATION_RESPONSE);
    }
}
