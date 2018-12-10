
// Don't edit, this file is automatically generated
// to check #include-ing of *all* headers
// /*
#include <mockpp/AbstractExpectationCollection.h>
#include <mockpp/Throwable.h>
#include <mockpp/ReturnObjectList.h>
#include <mockpp/ExpectationBoundary.h>
#include <mockpp/SelfDescribing.h>
#include <mockpp/mockpp_dbc.h>
#include <mockpp/MockObject.h>
#include <mockpp/ThrowableList.h>
#include <mockpp/VerifiableList.h>
#include <mockpp/visiting/ResponseVector4.h>
#include <mockpp/visiting/VisitableMockMethod4.h>
#include <mockpp/visiting/VisitableMockObject_template.h>
#include <mockpp/visiting/VisitableMockObject_macro.h>
#include <mockpp/visiting/ResponseVector5.h>
#include <mockpp/visiting/VisitableMockMethod6.h>
#include <mockpp/visiting/VisitableMockMethod0.h>
#include <mockpp/visiting/ResponseVector6.h>
#include <mockpp/visiting/ResponseVector3.h>
#include <mockpp/visiting/VisitableMockMethod.h>
#include <mockpp/visiting/VisitableMockMethod1.h>
#include <mockpp/visiting/VisitableMockMethod2.h>
#include <mockpp/visiting/VisitableMockMethod5.h>
#include <mockpp/visiting/CountedVisitableMethod.h>
#include <mockpp/visiting/ResponseVector1.h>
#include <mockpp/visiting/ResponseVector2.h>
#include <mockpp/visiting/VisitableMockMethod3.h>
#include <mockpp/visiting/VisitableMockObject.h>
#include <mockpp/constraint/ConstraintSet.h>
#include <mockpp/constraint/IsAnything.h>
#include <mockpp/constraint/ConstraintSetN.h>
#include <mockpp/constraint/And.h>
#include <mockpp/constraint/IsEqual.h>
#include <mockpp/constraint/Constraint.h>
#include <mockpp/constraint/TypelessConstraint.h>
#include <mockpp/constraint/IsSame.h>
#include <mockpp/constraint/IsInstanceOf.h>
#include <mockpp/constraint/TriggeredConstraint.h>
#include <mockpp/constraint/OutBound.h>
#include <mockpp/constraint/IsLessOrEqual.h>
#include <mockpp/constraint/IsNothing.h>
#include <mockpp/constraint/ConstraintHolder.h>
#include <mockpp/constraint/IsCloseTo.h>
#include <mockpp/constraint/ConstraintList.h>
#include <mockpp/constraint/StringContains.h>
#include <mockpp/constraint/IsGreaterThan.h>
#include <mockpp/constraint/Or.h>
#include <mockpp/constraint/StringStartsWith.h>
#include <mockpp/constraint/IsLessThan.h>
#include <mockpp/constraint/IsNot.h>
#include <mockpp/constraint/StringEndsWith.h>
#include <mockpp/constraint/IsGreaterOrEqual.h>
#include <mockpp/constraint/TriggeredOutbound.h>
#include <mockpp/ExpectationMap.h>
#include <mockpp/chaining/StubMatchersCollection.h>
#include <mockpp/chaining/CountedChainableMethod.h>
#include <mockpp/chaining/ChainableMockObject.h>
#include <mockpp/chaining/ChainableMockMethod5.h>
#include <mockpp/chaining/LIFOInvocationDispatcher.h>
#include <mockpp/chaining/ReturnValueAndCall.h>
#include <mockpp/chaining/ChainableMockMethod3.h>
#include <mockpp/chaining/AbstractInvocationDispatcher.h>
#include <mockpp/chaining/AbstractDynamicChainingMock.h>
#include <mockpp/chaining/ChainableMockMethod0.h>
#include <mockpp/chaining/InvocationMocker.h>
#include <mockpp/chaining/OnConsecutiveCalls.h>
#include <mockpp/chaining/Invokable.h>
#include <mockpp/chaining/ReturnValueAndTrigger.h>
#include <mockpp/chaining/ChainingMockObjectSupport.h>
#include <mockpp/chaining/DynamicChainingMock.h>
#include <mockpp/chaining/FIFOInvocationDispatcher.h>
#include <mockpp/chaining/ChainableMockMethod1.h>
#include <mockpp/chaining/mockpp_pti.h>
#include <mockpp/chaining/ChainableMockMethod4.h>
#include <mockpp/chaining/InvocationN.h>
#include <mockpp/chaining/ChainableMockMethod2.h>
#include <mockpp/chaining/ChainableMockMethod6.h>
#include <mockpp/chaining/CoreMock.h>
#include <mockpp/chaining/InvocationDispatcher.h>
#include <mockpp/chaining/ChainableMockObject_macro.h>
#include <mockpp/chaining/ChainingMockBuilder.h>
#include <mockpp/chaining/DynamicChainingMockError.h>
#include <mockpp/chaining/Invocation.h>
#include <mockpp/chaining/ChainableMockMethod.h>
#include <mockpp/ExpectationSet.h>
#include <mockpp/util/NotImplementedException.h>
#include <mockpp/util/AutoPointer.h>
#include <mockpp/util/AssertMo.h>
#include <mockpp/CountParameters.h>
#include <mockpp/matcher/TestFailureMatcher.h>
#include <mockpp/matcher/NoArgumentsMatcher.h>
#include <mockpp/matcher/StatelessInvocationMatcher.h>
#include <mockpp/matcher/InvokeAtLeastOnceMatcher.h>
#include <mockpp/matcher/InvokedRecorder.h>
#include <mockpp/matcher/InvokeOnceMatcher.h>
#include <mockpp/matcher/InvokeAtLeastMatcher.h>
#include <mockpp/matcher/UnlimitedMatcher.h>
#include <mockpp/matcher/MatcherHolder.h>
#include <mockpp/matcher/InvokedAfterMatcher.h>
#include <mockpp/matcher/InvokeCountMatcher.h>
#include <mockpp/matcher/InvocationMatcher.h>
#include <mockpp/matcher/TypelessMatcher.h>
#include <mockpp/matcher/ArgumentsMatcher.h>
#include <mockpp/matcher/InvokeAtMostMatcher.h>
#include <mockpp/matcher/InvokedBeforeMatcher.h>
#include <mockpp/matcher/AnyArgumentsMatcher.h>
#include <mockpp/MixedMockObject.h>
#include <mockpp/ExpectationValue.h>
#include <mockpp/ExpectationList.h>
#include <mockpp/ExpectationSegment.h>
#include <mockpp/stub/Stub.h>
#include <mockpp/stub/ThrowStub.h>
#include <mockpp/stub/TypelessStubSequence.h>
#include <mockpp/stub/CallStub.h>
#include <mockpp/stub/TriggerStub.h>
#include <mockpp/stub/RandomStub.h>
#include <mockpp/stub/TestFailureStub.h>
#include <mockpp/stub/StubSequence.h>
#include <mockpp/stub/TypelessStub.h>
#include <mockpp/stub/ReturnObjectListStub.h>
#include <mockpp/stub/ReturnAndCallStub.h>
#include <mockpp/stub/CustomStub.h>
#include <mockpp/stub/VoidStub.h>
#include <mockpp/stub/DefaultResultStub.h>
#include <mockpp/stub/StubHolder.h>
#include <mockpp/stub/ReturnStub.h>
#include <mockpp/stub/ReturnAndTriggerStub.h>
#include <mockpp/TrackingCounter.h>
#include <mockpp/MockTimeServer.h>
#include <mockpp/ExpectationCounter.h>
#include <mockpp/ExpectationConglomeration.h>
#include <mockpp/framework/SelectUnittestFramework.h>
#include <mockpp/framework/CxxTestSupport.h>
#include <mockpp/framework/VerifyingTestCaller.h>
#include <mockpp/framework/VerifyingTestCase.h>
#include <mockpp/framework/CxxTestRunner.h>
#include <mockpp/Expectation.h>
#include <mockpp/AbstractExpectation.h>
#include <mockpp/production/TimeServer.h>
#include <mockpp/production/mockpp_production.h>
#include <mockpp/compat/Formatter.h>
#include <mockpp/compat/Exception.h>
#include <mockpp/compat/Asserter.h>
#include <mockpp/compat/AssertionFailedError.h>
#include <mockpp/builder/ArgumentsMatchBuilderN.h>
#include <mockpp/builder/IdentityBuilder.h>
#include <mockpp/builder/MatchBuilder.h>
#include <mockpp/builder/BuilderNamespace.h>
#include <mockpp/builder/StubBuilder.h>
#include <mockpp/builder/InvocationMockerBuilder.h>
#include <mockpp/builder/ArgumentsMatchBuilder.h>
#include <mockpp/Verifiable.h>
#include <mockpp/mockpp.h>
// */
int main()
{
 return 0;
}