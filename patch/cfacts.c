void
setcfact(const Arg *arg) {
	float f;
	Client *c;

	c = selmon->sel;

	if (!arg || !c || !selmon->lt[selmon->sellt]->arrange)
		return;
	f = arg->f + c->cfact;
	if (arg->f == 0.0)
		f = 1.0;
	else if (f < 0.25 || f > 4.0)
		return;
	c->cfact = f;
	arrange(selmon);
}

void
getfacts(Monitor *m, float *mf, float *sf)
{
	float mfacts = 0, sfacts = 0;
	Client *c;

	for (c = nexttiled(m->clients); c; c = nexttiled(c->next)) {
		if (!m->nmaster || n < m->nmaster)
			mfacts += c->cfact;
		else
			sfacts += c->cfact;
	}
	*mf = mfacts;       // total factor of master area
	*sf = sfacts;       // total factor of slave area
}