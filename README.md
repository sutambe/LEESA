# Language for Embedded QuEry and TraverSAl (LEESA)

## Introduction
LEESA is a new way of writing traversals over typed object structures, such as XML documents and domain-specific models. LEESA (Language for Embedded quEry and traverSAl) is a domain-specific embedded language (DSEL) in C++ that:

See LEESA [hexagon](images/LEESA-hexagon.png).

* Provides a succinct and expressive notation for writing object structure traversal ([examples](http://www.dre.vanderbilt.edu/LEESA/examples.html)).
* Supports hierarchical visitors, decouples traversals from visitation actions, and improves visitor and traversal reusability.
* Provides C++ template-based combinators to write tree traversals in a strategic programming style.
* Supports XPath-like axis-oriented notation including structure-shyness (e.g., descendant-axis and wildcards).
* Reports any type related errors in the query at compile-time.
* Significantly reduces the development cost of programs operating on complex object structures (e.g., XML document traversal, domain-specific modeling language (DSML) interpreters) compared to the traditional techniques.

LEESA is embedded in C++ using sophisticated generic and meta programming techniques. LEESA's toolchain supports the following XML data-binding technologies:

* [CodeSynthesis XSD](http://codesynthesis.com/products/xsd)
* [ISIS Universal Data Model (UDM)](http://repo.isis.vanderbilt.edu/tools/get_tool?UDM)

See the comparison of XML traversal code in `tests/library-xsd/driver.cxx` with and without LEESA. This program uses `tests/library-xsd/library.xsd` and `tests/library-xsd/library.xml`.

## Typed XML Programming

[Typed XML programing](http://blogs.msdn.com/xmlteam/archive/2006/07/20/673097.aspx) identifies the lack of fidelity in contemporary X-to-O mapping (XML data binding) tools towards supporting XML semantics and programming patterns & practices native to the XML domain. LEESA, however, recognizes the practical usefulness of these mappings and attempts to improve the extraction of typed data by incorporating the idioms of XML querying (think XPath axes, wildcards) without losing the grip on types. In that sense it supports typed XML programming and alleviates the disappointment of a XML programmer in the typed world. See some examples.

## Research Papers

* [Toward Native XML Processing Using Multi-paradigm Design in C++](http://www.dre.vanderbilt.edu/~sutambe/documents/pubs/LEESA-Multiparadigm.pdf) in the 5th Annual Boost Conference (BoostCon-2011) ([slides](http://www.dre.vanderbilt.edu/~sutambe/documents/pubs/ppt/LEESA-BoostCon.pdf)) ([video](https://vimeo.com/104812737))
* [LEESA: Embedding Strategic and XPath-like Object Structure Traversals in C++](http://www.dre.vanderbilt.edu/~sutambe/documents/pubs/LEESA-DSL09.pdf) published in the IFIP Working Conference on Domain Specific Languages (DSL WC), 2009, Oxford UK (slides)
* [An Embedded Declarative Language for Hierarchical Object Structure Traversal](http://www.dre.vanderbilt.edu/~sutambe/documents/pubs/LEESA-DSPD08.pdf) published in the 2nd International Workshop on Domain-Specific Program Development (DSPD), GPCE 2008, Nashville, Tennessee, October 22, 2008 (slides)

## Installation

#### Linux

1. Obtain xsdcxx  
   Fedora: `sudo yum install xsdcxx`
   Ubuntu: `sudo apt-get install xsdcxx`
   If xsdcxx can't be installed, obtain xsdcxx from [CodeSynthesis](http://www.codesynthesis.com/products/xsd/download.xhtml) 
   and set `$XSD_ROOT` to the root directory of the installation.

2. Install python, libxslt, libxml2, doxygen, xsltproc, python-setuptools, and xerces-c.
   Fedora: `sudo yum install python-devel libxslt-devel libxml2-devel doxygen xerces-c-devel python-setuptools-devel`
   Ubuntu: `sudo apt-get install python-dev libxslt1-dev libxml2-dev doxygen xsltproc libxerces-c-dev python-setuptools`

3. Install Boost C++ libraries. LEESA depends on Boost MPL.

4. Install lxml Python bindings.
   `sudo easy_install lxml`

5. Clone this repo. `cd LEESA`

6. Set `$LEESA_ROOT`, `$XSD_ROOT`, `$BOOST_ROOT` environment variables

7. `cd $LEESA_ROOT/tests/library-xsd`

7. `make generate`

8. `make driver`

9. `./driver library.xml`


#### Windows

1. Obtain xsd from [CodeSynthesis](http://www.codesynthesis.com/products/xsd/download.xhtml) 
   and set `%XSD_ROOT%` to the root directory of the installation.

2. Install python, doxygen, and xsltproc.
   Make sure they are accessible from %PATH%

3. Clone this repo. `cd LEESA`

4. Set `%LEESA_ROOT%`

5. Obtain Boost from www.boost.org. LEESA depends on Boost MPL.
   Set `%BOOST_ROOT%`

6. Use .sln file to open the projects in Visual Studio.

7. Run driver
   `driver.exe library.xml`
