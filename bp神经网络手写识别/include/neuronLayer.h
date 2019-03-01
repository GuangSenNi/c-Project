#ifndef NEURONLAYER_H
#define NEURONLAYER_H


class neuronLayer
{
    public:
        neuronLayer(int numNeurons, int numInputsPerNeuron); /** ��ϸ����Ĺ��캯��*/
        neuronLayer(neuronLayer& nl); /** ��ϸ����Ŀ������캯�� */
        virtual ~neuronLayer();
        int mNumInputsPerNeuron; /** ��ǰ���ÿ����ϸ����������Ŀ */
        int mNumNeurons; /** ��ǰ�����ϸ����Ŀ */
        double** mWeights; /** 2ά����, ��: ������ϸ����ÿһ�о���һ����ϸ��������Ȩ�أ�, ��: ������ϸ��������Ȩ�� */
        double* mOutActivations; /** ��ǰ��ÿ����ϸ�������ֵ */
        double* mOutErrors; /** ��ǰ��ÿ����ϸ�������ֵ */

    protected:

    private:
};

#endif // NEURONLAYER_H
