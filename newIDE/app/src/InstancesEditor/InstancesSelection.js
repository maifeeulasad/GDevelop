// @flow
const gd: libGDevelop = global.gd;

/**
 * Represents a list of selected instances.
 */
export default class InstancesSelection {
  selection: Array<gdInitialInstance> = [];

  hasSelectedInstances() {
    return !!this.getSelectedInstances().length;
  }

  getSelectedInstances() {
    return this.selection;
  }

  isInstanceSelected(instance: gdInitialInstance) {
    for (var i = 0; i < this.selection.length; i++) {
      if (gd.compare(this.selection[i], instance)) return true;
    }

    return false;
  }

  clearSelection() {
    this.selection.length = 0;
  }

  selectInstance(
    instance: gdInitialInstance,
    multiselect: boolean,
    layersVisibility: ?{ [string]: boolean } = null
  ) {
    if (this.isInstanceSelected(instance)) {
      if (multiselect) this.unselectInstance(instance);

      return;
    }

    if (!multiselect) this.clearSelection();

    if (!layersVisibility || layersVisibility[instance.getLayer()]) {
      this.selection.push(instance);
    }
  }

  selectInstances(
    instances: Array<gdInitialInstance>,
    multiselect: boolean,
    layersVisibility: ?{ [string]: boolean } = null
  ) {
    if (!multiselect) this.clearSelection();

    instances.forEach(instance =>
      this.selectInstance(instance, true, layersVisibility)
    );
  }

  unselectInstance(instance: gdInitialInstance) {
    if (this.isInstanceSelected(instance)) {
      var i = this.selection.length - 1;
      while (i >= -1 && this.selection[i].ptr !== instance.ptr) {
        --i;
      }

      this.selection.splice(i, 1);
    }
  }

  unselectInstancesOfObject(objectName: string) {
    for (let i = 0; i < this.selection.length; ) {
      if (this.selection[i].getObjectName() === objectName) {
        this.selection.splice(i, 1);
      } else {
        i++;
      }
    }
  }

  unselectInstancesOnLayer(layerName: string) {
    for (let i = 0; i < this.selection.length; ) {
      if (this.selection[i].getLayer() === layerName) {
        this.selection.splice(i, 1);
      } else {
        i++;
      }
    }
  }
}
