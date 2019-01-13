import os
equations=['duffing','linear','lorenz']
integrators=['euler','rk4','ab2']
time=25.0
tstep=[0.01,0.001]
for eq in equations:
	for integ in integrators:
		filename=eq + '_' + integ+'_conv.out'
		os.system('>' + filename)
		for step in tstep:
			nstep=time/step
			os.system('echo -n '+str( step)  + '>>' + filename)
			os.system('echo -n \'\t\'' + '>>' + filename)
			os.system('./ode_solve' +' '+eq +' '+ integ +' '+ str(step)+' '+ str(nstep) + '>>' +  filename)
