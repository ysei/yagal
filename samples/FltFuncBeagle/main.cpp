#include <beagle/GA.hpp>
#include <vector>
#include <stdio.h>

using namespace std;
using namespace Beagle;

class MaxFctFloatEvalOp : public EvaluationOp {
public:
    typedef Beagle::AllocatorT<MaxFctFloatEvalOp, EvaluationOp::Alloc> Alloc;
    typedef Beagle::PointerT<MaxFctFloatEvalOp, EvaluationOp::Handle> Handle;
    typedef Beagle::ContainerT<MaxFctFloatEvalOp, EvaluationOp::Bag> Bag;

    explicit MaxFctFloatEvalOp() : EvaluationOp("MaxFctFloatEvalOp") {}

    virtual Beagle::Fitness::Handle evaluate(Beagle::Individual& inIndividual,
                                             Beagle::Context& ioContext) {
        Beagle_AssertM(inIndividual.size() == 1);
        GA::FloatVector::Handle lFloatVector = castHandleT<GA::FloatVector>(inIndividual[0]);
        Beagle_AssertM(lFloatVector->size() == 2);

        float y;
        y = - (*lFloatVector)[0] * (*lFloatVector)[0];
        y -= (*lFloatVector)[1] * (*lFloatVector)[1];

        return new FitnessSimple(y);
    }
};

int main(int argc, char ** argv)
{
    try {
        System::Handle lSystem = new System;
        const unsigned int lVectorSize = 2;
        lSystem->addPackage(new GA::PackageFloatVector(lVectorSize));
        lSystem->addPackage(new GA::PackageCMAES(lVectorSize));
        lSystem->setEvaluationOp("MaxFctFloatEvalOp", new MaxFctFloatEvalOp::Alloc);
        Evolver::Handle lEvolver = new Evolver;
        lEvolver->initialize(lSystem, argc, argv);
        Vivarium::Handle lVivarium = new Vivarium;
        lEvolver->evolve(lVivarium, lSystem);
        Individual::Handle ind = ((lVivarium->getHallOfFame())[0]).mIndividual;

        GA::FloatVector::Handle inIndividual = castHandleT<GA::FloatVector>((*(lVivarium->getHallOfFame().getPointer()))[0].mIndividual);
        cout << "the ga found an optimum at the point (";
        cout << (*inIndividual)[0] << ", " << (*inIndividual)[1] << ")\n\n";

    }
    catch(Exception& inException) {
        inException.terminate(cerr);
    }
    catch(std::exception& inException) {
        cerr << "Standard exception catched:" << endl << flush;
        cerr << inException.what() << endl << flush;
        return 1;
    }
    return 0;
}
