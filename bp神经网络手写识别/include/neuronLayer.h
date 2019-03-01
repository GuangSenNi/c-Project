#ifndef NEURONLAYER_H
#define NEURONLAYER_H


class neuronLayer
{
    public:
        neuronLayer(int numNeurons, int numInputsPerNeuron); /** 神经细胞层的构造函数*/
        neuronLayer(neuronLayer& nl); /** 神经细胞层的拷贝构造函数 */
        virtual ~neuronLayer();
        int mNumInputsPerNeuron; /** 当前层的每个神经细胞的输入数目 */
        int mNumNeurons; /** 当前层的神经细胞数目 */
        double** mWeights; /** 2维数组, 行: 代表神经细胞（每一行就是一个神经细胞的所有权重）, 列: 代表神经细胞的输入权重 */
        double* mOutActivations; /** 当前层每个神经细胞的输出值 */
        double* mOutErrors; /** 当前层每个神经细胞的误差值 */

    protected:

    private:
};

#endif // NEURONLAYER_H
