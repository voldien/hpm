using Microsoft.VisualStudio.TestTools.UnitTesting;
using HpmSharp;

namespace test
{
    [TestClass]
    public class UnitTest1
	{

		[TestInitialize]
		public void TestInitialize()
		{
			Hpm.init(SIMD.HPM_DEFAULT);
		}

        [TestMethod]
        public void TestMethod1()
		{

            Vector4 vec = new Vector4();
			//vec = MathUtil.Max(vec, vec);
			//Assert.AreEqual(vec, vec);
		}

        [TestMethod]
        public void TestMethod2()
		{

			Matrix4x4 vec = new Matrix4x4();
			Matrix4x4 vec2 = new Matrix4x4();
			Matrix4x4 m3 = vec * vec2;
			Assert.AreEqual(vec, vec);
		}
    }
}
