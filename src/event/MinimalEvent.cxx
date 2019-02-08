#include "event/MinimalEvent.hxx"

namespace nuis {
namespace event {
MinimalEvent::MinimalEvent()
    : mode(Channel_t::kUndefined), probe_E(0), probe_pdg(0), XSecWeight(1),
      RWWeight(1) {}

MinimalEvent::MinimalEvent(MinimalEvent &&other)
    : mode(other.mode), probe_E(other.probe_E), probe_pdg(other.probe_pdg),
      XSecWeight(other.XSecWeight), RWWeight(other.RWWeight) {}

MinimalEvent &MinimalEvent::operator=(MinimalEvent &&other) {
  mode = other.mode;
  probe_E = other.probe_E;
  probe_pdg = other.probe_pdg;
  XSecWeight = other.XSecWeight;
  RWWeight = other.RWWeight;

  return *this;
}

MinimalEvent MinimalEvent::Clone() const {
  MinimalEvent clone;
  clone.mode = mode;
  clone.probe_E = probe_E;
  clone.probe_pdg = probe_pdg;
  clone.XSecWeight = XSecWeight;
  clone.RWWeight = RWWeight;

  return clone;
}
} // namespace event
} // namespace nuis
