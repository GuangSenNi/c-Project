#ifndef BPNEURONNET_H
#define BPNEURONNET_H


class bpNeuronNet
{
    public:
        bpNeuronNet(int numInputs, double learningRate);
        virtual ~bpNeuronNet();
        bool train(const double input[],const double target[]);
        void process(const double input[],double *output[]);
        void reset(void); /** �������� */
        void addNeuronLayer(int numNeurons); /** ���һ��������� */

    protected:

    private:
        /** sigmoid(S��)����� */
        inline double sigmoidActive(double activation, double response);
        void updateNeuronLayer(neuronLayer& nl, const double inputs[]);
    private:
        int mNumInputs; /** �������������Ŀ */
        int mNumOutputs; /** ������������Ŀ */
        /** ��������Ŀ���ܵ�����������Ŀ= mNumHiddenLayers + 1
        * ������������㣬��Ϊ����ֱ��ӳ�䵽��һ�������㣬û����ϸ�� �� */
        int mNumHiddenLayers;
        /** �������ѧϰ�ʣ���ʾѧϰ�ٶȵģ�����Ҫ����ѡ��̫�����ִ������������޷�������
        * ̫СҲ���ܵ��´�����������ѧϰ�ٶȱ��� */
        double mLearningRate;
        double mErrorSum; /** ���������ο���getError���� */
        vector<neuronLayer*> mNeuronLayers; /** �������������ϸ�������� */
};

#endif // BPNEURONNET_H
