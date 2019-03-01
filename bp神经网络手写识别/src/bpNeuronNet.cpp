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
{/** reponse ���������� activation�ģ�ȡֵ��Χ�� 0 < response <= 1.0 */
    /** sigmoid function: f(x) = 1 /(1 + exp(-x)) */
    return (1.0 / (1.0 + exp(-activation * response)));
}

void bpNeuronNet::updateNeuronLayer(neuronLayer& nl, const double inputs[])
{
    int numNeurons = nl.mNumNeurons; /** ��ǰ���ж��ٸ���ϸ�� */
    int numInputsPerNeuron = nl.mNumInputsPerNeuron; /** ��ǰ���ÿһ����ϸ���ж������� */
    double* curOutActivations = nl.mOutActivations; /** ��ǰ��������ϸ�������ֵ���� */

    /** ����ÿһ����ϸ�� */
    for (int n = 0; n < numNeurons; ++n)
    {
        double* curWeights = nl.mWeights[n]; /** ��ȡ��n����ϸ��������Ȩ������ */

        double netinput = 0;
        int k;
        /** ����ÿһ������Ȩ�� */
        for (k = 0; k < numInputsPerNeuron; ++k)
        {
            /*** �ۼ� weights �� inputs�ĳ˻� */
            netinput += curWeights[k] * inputs[k];
        }

        /** ���ƫ�����ֵ */
        netinput += curWeights[k] * BIAS;


        /** ���ۼӺ��ֵͨ����������õ���ǰ��ϸ����������� */
        curOutActivations[n] = sigmoidActive(netinput, ACTIVATION_RESPONSE);
    }
}
