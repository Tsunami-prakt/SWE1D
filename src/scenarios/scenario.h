#ifndef SCENARIOS_SCENARIO_H_
#define SCENARIOS_SCENARIO_H_

namespace scenarios
{

/**
 * A standard scenario where there are only
 * two different wave vectors "meeting" each other at some
 * position \f$x_{dis}\f$ which defaults to the middle of the
 * scenario size \f$\lfloor{x/2}\rfloor\f$.
 */
template <typename T> class Scenario
{

protected:

    /**
     * The constructor for a standard scenario
     *
     * @param [in] size The number of cells
     * @param [in] hl The height of the left wave vector
     * @param [in] hr The height of the right wave vector
     * @param [in] hul The momentum of the left wave vector
     * @param [in] hur THe momentum of the right wave vector
     */
    Scenario(unsigned int size, const T hl, const T hr, const T hul, const T hur) : m_size(size), m_hul(hul), m_hur(hur), m_hl(hl), m_hr(hr) {}
    /** Number of cells */
    const unsigned int m_size;
    const T m_hul;
    const T m_hur;
    const T m_hl;
    const T m_hr;

public:
    //Scenario(unsigned int size) : m_size(size) { }

    /**
     * @return Initial water height at pos
     */
    virtual T getHeight(unsigned int pos) = 0;

    /**
     * @return Space time dependent momentum at pos
     */
    virtual T getMomentum(unsigned int pos) = 0;

    /**
     * @return Cell size of one cell (= domain size/number of cells)
     */
    virtual T getCellSize()
    {
        return 1000.f / m_size;
    }
};
};

#endif
