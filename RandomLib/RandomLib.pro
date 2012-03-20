TEMPLATE = lib
QT -= gui
CONFIG += staticlib release

INCLUDEPATH = ..

TARGET = ../lib/RandomLib

HEADERS += ExactExponential.hpp \
	ExactNormal.hpp \
	ExactPower.hpp \
	ExponentialDistribution.hpp \
	ExponentialProb.hpp \
	InverseEProb.hpp \
	InversePiProb.hpp \
	LeadingZeros.hpp \
	MPFRExponential.hpp \
	MPFRExponentialL.hpp \
	MPFRNormal.hpp \
	MPFRNormalK.hpp \
	MPFRNormalR.hpp \
	MPFRRandom.hpp \
	MPFRUniform.hpp \
	NormalDistribution.hpp \
	Random.hpp \
	RandomAlgorithm.hpp \
	RandomCanonical.hpp \
	RandomEngine.hpp \
	RandomMixer.hpp \
	RandomNumber.hpp \
	RandomPower2.hpp \
	RandomSeed.hpp \
	RandomSelect.hpp \
	RandomType.hpp
	
SOURCES += Random.cpp

QMAKE_CXXFLAGS = -msse2
