///////////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2012 maintech GmbH, Otto-Hahn-Str. 15, 97204 Hoechberg, Germany     //
// written by Christian Daniel                                                       //
// Copyright (C) 2020 Edouard Griffiths, F4EXB <f4exb06@gmail.com>                   //
// Copyright (C) 2023 Jon Beniston, M7RCE <jon@beniston.com>                         //
//                                                                                   //
// This program is free software; you can redistribute it and/or modify              //
// it under the terms of the GNU General Public License as published by              //
// the Free Software Foundation as version 3 of the License, or                      //
// (at your option) any later version.                                               //
//                                                                                   //
// This program is distributed in the hope that it will be useful,                   //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                    //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                      //
// GNU General Public License V3 for more details.                                   //
//                                                                                   //
// You should have received a copy of the GNU General Public License                 //
// along with this program. If not, see <http://www.gnu.org/licenses/>.              //
///////////////////////////////////////////////////////////////////////////////////////
#include "dsp/kissengine.h"

const QString KissEngine::m_name = "Kiss";

QString KissEngine::getName() const
{
    return m_name;
}

void KissEngine::configure(int n, bool inverse)
{
	m_fft.configure(n, inverse);
	if(n > m_in.size())
		m_in.resize(n);
	if(n > m_out.size())
		m_out.resize(n);
}

void KissEngine::transform()
{
    PROFILER_START()

	m_fft.transform(&m_in[0], &m_out[0]);

    PROFILER_STOP(QString("%1 %2").arg(getName()).arg(m_out.size()))
}

Complex* KissEngine::in()
{
	return &m_in[0];
}

Complex* KissEngine::out()
{
	return &m_out[0];
}

void KissEngine::setReuse(bool reuse)
{
    (void) reuse;
}
