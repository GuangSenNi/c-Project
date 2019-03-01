#ifndef BPNEURONNET_H
#define BPNEURONNET_H


class bpNeuronNet
{
    public:
        bpNeuronNet(int numInputs, double learningRate);
        virtual ~bpNeuronNet();
        bool train(const double input[],const double target[]);
        void process(const double input[],double *output[]);
        void reset(void); /** 重置网络 */
        void addNeuronLayer(int numNeurons); /** 添加一个神经网络层 */

    protected:

    private:
        /** sigmoid(S型)激活函数 */
        inline double sigmoidActive(double activation, double response);
        void updateNeuronLayer(neuronLayer& nl, const double inputs[]);
    private:
        int mNumInputs; /** 神经网络的输入数目 */
        int mNumOutputs; /** 神经网络的输出数目 */
        /** 隐含层数目，总的神经网络层的数目= mNumHiddenLayers + 1
        * （不包含输入层，因为它是直接映射到第一个隐含层，没有神经细胞 ） */
        int mNumHiddenLayers;
        /** 神经网络的学习率（表示学习速度的），需要慎重选择，太大会出现错误收敛或者无法收敛，
        * 太小也可能导致错误收敛，且学习速度变慢 */
        double mLearningRate;
        double mErrorSum; /** 忘了总误差，参看：getError函数 */
        vector<neuronLayer*> mNeuronLayers; /** 神经网络包含的神经细胞层数组 */
};

#endif // BPNEURONNET_H
