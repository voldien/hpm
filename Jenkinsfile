pipeline {
	agent {
		docker {
			label 'docker'
			image 'node:14-alpine'
		}
	}

	stages {
		stage('Build') {
			steps {
				echo 'Building..'
				cmakeBuild  installation: "InSearchPath",
											generator: "Unix Makefile",
											buildDir: 'build',
											sourceDir: 'source',
											steps: [
												[args: 'all install']
											]
			}
		}
		stage('Test') {
			steps {
				echo 'Testing..'
				ctest 'InSearchPath'
			}
		}
		stage('Deploy') {
			steps {
				echo 'Deploying....'
			}
		}
	}
}